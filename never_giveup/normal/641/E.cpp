#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e6 + 10;

int n, m;

struct treap{
    int x, y, val, sum;
    treap *l, *r;
};

typedef treap * ptr;

ptr create(int x, int val){
    ptr t = new treap;
    t->x = x;
    t->y = rand();
    t->val = val;
    t->sum = val;
    t->l = nullptr;
    t->r = nullptr;
    return t;
}

int sum(ptr t){
    return t == nullptr ? 0 : t->sum;
}

void upd(ptr &t){
    if (t != nullptr)
        t->sum = t->val + sum(t->l) + sum(t->r);
}

void split(ptr t, ptr &l, ptr &r, int key){
    if (t == nullptr){
        l = nullptr;
        r = nullptr;
        return;
    }
    upd(t);
    if (t->x <= key)
        split(t->r, t->r, r, key), l = t;
    else
        split(t->l, l, t->l, key), r = t;
    upd(l);
    upd(r);
}

/*void merge(ptr &t, ptr l, ptr r){
    if (l == nullptr){
        t = r;
        return;
    }
    if (r == nullptr){
        t = l;
        return;
    }
    upd(l);
    upd(r);
    if (l->y <= r->y)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd(t);
}*/

void insert(ptr &t, ptr ins){
    if (t == nullptr){
        t = ins;
        return;
    }
    if (t->y >= ins->y){
        split(t, ins->l, ins->r, ins->x), t = ins;
    }
    else
    if (t->x <= ins->x)
        insert(t->r, ins);
    else
        insert(t->l, ins);
    upd(t);
}

void myinsert(ptr &t, int x, int val){
    ptr ins = create(x, val);
    insert(t, ins);
}

pair<int, pair<int, int> > zap[maxn];

map<int, int> mp;

int cnt = 0;

ptr root[maxn];

int Sum(ptr t, int key){
    if (t == nullptr)
        return 0;
    if (t->x <= key)
        return sum(t->l) + t->val + Sum(t->r, key);
    return Sum(t->l, key);
}

int main(){
    ios::sync_with_stdio(0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        root[i] = nullptr;
    for (int i = 0; i < n; i++){
        scanf("%d %d %d", &zap[i].first, &zap[i].second.first, &zap[i].second.second);
        if (mp.find(zap[i].second.second) == mp.end())
           mp[zap[i].second.second] = cnt, cnt++;
        zap[i].second.second = mp[zap[i].second.second];
    }
    for (int i = 0; i < n; i++){
        if (zap[i].first == 1)
            myinsert(root[zap[i].second.second], zap[i].second.first, 1);
        else
        if (zap[i].first == 2)
            myinsert(root[zap[i].second.second], zap[i].second.first, -1);
        else
            printf("%d\n", Sum(root[zap[i].second.second], zap[i].second.first));
    }
}