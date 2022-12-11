#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e6 + 50;
int a[maxn];
int cnt = 0;
set<int> s;
int x;
int main()
{
    int n;
    cin>> n >> x;
    for(int i = 1; i < (1<<n); ++i){
        if(i == x) continue;
        s.insert(i);
    }
    while(s.size()){
        int t = *s.begin();
        s.erase(t);
        s.erase(t^x);
        a[cnt++] = t;
    }
    for(int i = cnt-1; i > 0; --i) a[i] = a[i]^a[i-1];
    printf("%d\n",cnt);
    for(int i = 0; i < cnt; ++i) printf("%d ",a[i]);
}