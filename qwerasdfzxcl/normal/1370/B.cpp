#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[2020];
vector<int> e, o;

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<2*n;i++) scanf("%d", a+i);
    e.clear(); o.clear();
    for (int i=0;i<2*n;i++){
        if (a[i]&1) o.push_back(i+1);
        else e.push_back(i+1);
    }
    if ((int)o.size()&1){
        for (int i=0;i<((int)o.size()-1)/2;i++) printf("%d %d\n", o[i*2], o[i*2+1]);
        for (int i=0;i<((int)e.size()-1)/2;i++) printf("%d %d\n", e[i*2], e[i*2+1]);
        return;
    }
    else if ((int)o.size()==0){
        for (int i=0;i<(int)e.size()/2-1;i++) printf("%d %d\n", e[i*2], e[i*2+1]);
        return;
    }
    for (int i=0;i<(int)o.size()/2-1;i++) printf("%d %d\n", o[i*2], o[i*2+1]);
    for (int i=0;i<(int)e.size()/2;i++) printf("%d %d\n", e[i*2], e[i*2+1]);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}