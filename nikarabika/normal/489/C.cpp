#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<int, int> pie;

int m, ss;
int a[150];

bool make_sm(int p, int s){
    if(s<0 || s>(m-p)*9)
        return false;
    if(p==m-1){
        a[p]=s;
        return true;
    }
    for(int i=0; i<=9; i++){
        a[p]=i;
        if(make_sm(p+1, s-i))
            return true;
    }
    return false;
}

bool make_bg(int p, int s){
    if(s>(m-p)*9 || s<0)
        return false;
    if(p==m-1){
        a[p]=s;
        return true;
    }
    for(int i=9; i>=0; i--){
        a[p]=i;
        if(make_bg(p+1, s-i))
            return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin>>m>>ss;
    if(m==1 && ss==0){
        cout<<"0 0"<<endl;
        return 0;
    }
    if(ss>9*m || ss<1){
        cout<<"-1 -1"<<endl;
        return 0;
    }
    if(m==1){
        if(ss>9)
            cout<<"-1 -1"<<endl;
        else
            cout<<ss<<' '<<ss<<endl;
        return 0;
    }
    bool x=false;
    FOR(i, 1, 9){
        a[0]=i;
        if(make_sm(1, ss-i)){
            x=true;
            break;
        }
    }
    if(x){
        for(int i=0; i<m; i++)
            cout<<a[i];
        cout<<' ';
    }
    else{
        cout<<"-1 -1"<<endl;
        return 0;
    }
    x=false;
    if(make_bg(0, ss));
        rep(i, m)
            cout<<a[i];
    cout<<endl;
    return 0;
}