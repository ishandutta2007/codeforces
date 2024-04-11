#include <bits/stdc++.h>
using namespace std;

int q;

struct Node {    
    int size;
    Node *child[2];
    
    Node () {
        size = 0;
        child[0] = child[1] = 0;
    }
} *root;

int getSize (Node *node) {
    return node ? node->size : 0;
}   

void update (Node *node) {
    node->size = getSize(node->child[0]) + getSize(node->child[1]);
}

Node *insert (Node *now, int val, int depth = 30) {    
    if (!now) now = new Node();
    
    if (depth < 0) {
        (now->size)++;
        return now;
    }
    
    now->child[val >> depth & 1] = insert(now->child[val >> depth & 1], val, depth - 1);
    update(now);
    
    return now;
}

void erase (Node *now, int val, int depth = 30) {
    if (depth < 0) {
        (now->size)--;
        return;
    }
    
    erase(now->child[val >> depth & 1], val, depth - 1);
    update(now);
}

int query (Node *now, int val, int depth = 30) {
    if (depth < 0) return 0;
    if (!now) return val;
    
    if (val >> depth & 1) {
        if (getSize(now->child[0])) return (1 << depth) + query(now->child[0], val, depth - 1);
        return query(now->child[1], val, depth - 1);
    } else {
        if (getSize(now->child[1])) return (1 << depth) + query(now->child[1], val, depth - 1);
        return query(now->child[0], val, depth - 1);
    }
}

int main() {

    root = insert(root, 0);

    scanf ("%d", &q);
    while (q--) {
        getchar();
        
        char c; int x;
        scanf ("%c %d", &c, &x);        
        
        if (c == '+') {
            root = insert(root, x);
        } else if (c == '-') {
            erase(root, x);
        } else if (c == '?') {
            printf ("%d\n", query(root, x));
        }
    }
    return 0;
}