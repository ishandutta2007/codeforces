#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second
#define t abs

int main(){

    int n;
    cin >> n;
    int st[n];
    int k;
    vector<int>g[n];
    queue<int>v;
    for(int i = 0;i<n;i++){
        st[i] = 1e9;
    }
    for(int i = 0;i<n;i++){
        cin >> k;
        if(k==-1){
            v.push(i);
            st[i] = 0;
        }
        else{
            k--;
            g[k].push_back(i);
        }
    }
    while(v.size()>0){
        for(int i = 0;i<g[v.front()].size();i++){
            if(st[g[v.front()][i]]== 1e9){
                st[g[v.front()][i]] = st[v.front()]+1;
                v.push(g[v.front()][i]);
            }
        }
        v.pop();
    }
    int mx = 0;
    for(int i = 0;i<n;i++){
        mx = max(st[i],mx);
    }
    cout << mx+1;
    return 0;
}