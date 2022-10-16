#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryIndexedTree {
    int N;
    vector<T>bit;
    BinaryIndexedTree(){}
    BinaryIndexedTree(int x) {
        N = x;
        bit.resize(x+1);
    }
    void add(int x,T y) {
        while(x <= N) {
            bit[x] += y;
            x += x&-x;
        }
    }
    T sum(int x) {
        T res = 0;
        while(x) {
            res += bit[x];
            x -= x&-x;
        }
        return res;
    }
    inline T sum(int l, int r) {//[l,r]
        return sum(r)-sum(l-1);
    }
    inline T operator[](int k) {
        return sum(k)-sum(k-1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int>L(N),R(N);
    for(int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
    }
    vector<int>ans(30);
    for(int i = 0; i < 30; i++) {
        vector<pair<int,int>>tmp;
        vector<int>cmp;
        for(int j = 0; j < N; j++) {
            if(L[j]+(1 << i)-1 <= R[j]) {
                ans[i]++;
            }
            else {
                int l = L[j]%(1 << i);
                int r = R[j]%(1 << i);
                if(l <= r) {
                    tmp.push_back({l,r+1});
                    cmp.push_back(l);
                    cmp.push_back(r+1);
                }
                else {
                    tmp.push_back({l,(1 << i)});
                    cmp.push_back(l);
                    cmp.push_back((1 << i));
                    tmp.push_back({0,r+1});
                    cmp.push_back(0);
                    cmp.push_back(r+1);
                }
            }
        }
        sort(cmp.begin(),cmp.end());
        cmp.erase(unique(cmp.begin(),cmp.end()),cmp.end());
        BinaryIndexedTree<int> bit(cmp.size());
        for(int j = 0; j < tmp.size(); j++) {
            tmp[j].first = lower_bound(cmp.begin(),cmp.end(),tmp[j].first)-cmp.begin();
            tmp[j].second = lower_bound(cmp.begin(),cmp.end(),tmp[j].second)-cmp.begin();
            bit.add(tmp[j].first+1,1);
            bit.add(tmp[j].second+1,-1);
        }
        int mx = 0;
        for(int j = 1; j <= cmp.size(); j++) {
            mx = max(mx,bit.sum(j));
        }
        ans[i] += mx;
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int W;
        cin >> W;
        for(int i = 0; i < 30; i++) {
            if(1 & (W >> i)) {
                cout << ans[i] << "\n";
                break;
            }
        }
    }
}