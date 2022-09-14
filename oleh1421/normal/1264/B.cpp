#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a,b,c,d;cin>>a>>b>>c>>d;
    if (a==b+1 && c==0 && d==0){
        cout<<"YES\n";
        cout<<"0 ";
        for (int i=1;i<=b;i++) cout<<"1 0 ";
        return 0;
    }
    if (d==c+1 && a==0 && b==0){
        cout<<"YES\n";
        cout<<"3 ";
        for (int i=1;i<=c;i++) cout<<"2 3 ";
        return 0;
    }
    if (a>b || d>c){
        cout<<"NO\n";
        return 0;
    }
    int x=b-a;
    int y=c-d;
    if (x==y+1){
        cout<<"YES\n";
        cout<<"1 ";
        for (int i=1;i<=a;i++) cout<<"0 1 ";
        for (int i=1;i<=y;i++) cout<<"2 1 ";
        for (int i=1;i<=d;i++) cout<<"2 3 ";
        return 0;
    }
    if (y==x+1){
        cout<<"YES\n";
        for (int i=1;i<=a;i++) cout<<"0 1 ";
        for (int i=1;i<=x;i++) cout<<"2 1 ";
        for (int i=1;i<=d;i++) cout<<"2 3 ";
        cout<<"2";
        return 0;
    }
    if (x==y){
        cout<<"YES\n";
        for (int i=1;i<=a;i++) cout<<"0 1 ";
        for (int i=1;i<=x;i++) cout<<"2 1 ";
        for (int i=1;i<=d;i++) cout<<"2 3 ";
        return 0;
    }
    cout<<"NO";
    return 0;
}