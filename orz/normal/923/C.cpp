#include <iostream>
#include <vector>

#define long long long

using namespace std;

struct Node {
    int count;

    Node *zero = nullptr, *one = nullptr;

    explicit Node(int count) : count(count) {};
};

void add(Node *node, int value, int bit) {
    if (bit == -1) {
        node->count++;
        return;
    }
    node->count++;
    if (((value >> bit) & 1) == 0) {
        if (node->zero == nullptr) {
            node->zero = new Node(0);
        }
        add(node->zero, value, bit - 1);
    } else {
        if (node->one == nullptr) {
            node->one = new Node(0);
        }
        add(node->one, value, bit - 1);
    }
}

int find(Node *node, int value, int bit) {
    if (bit == -1) {
        if (node != nullptr) {
            node->count--;
        }
        return 0;
    }
    node->count--;
    if (((value >> bit) & 1) == 0) {
        if (node->zero != nullptr && node->zero->count > 0) {
            return find(node->zero, value, bit - 1);
        } else {
            return (1 << bit) + find(node->one, value, bit - 1);
        }
    } else {
        if (node->one != nullptr && node->one->count > 0) {
            return (1 << bit) + find(node->one, value, bit - 1);
        } else {
            return find(node->zero, value, bit - 1);
        }
    }
}

int main() {

    int n;
    cin >> n;

    Node root(0);
    vector<int> data(static_cast<unsigned int>(n));
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        add(&root, key, 29);
    }

    for (int i = 0; i < n; i++) {
        cout << (data[i] ^ find(&root, data[i], 29)) << ' ';
    }

    cout << '\n';
    return 0;

}