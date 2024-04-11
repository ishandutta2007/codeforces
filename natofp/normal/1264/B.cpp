#include <bits/stdc++.h>
#define ll long long int
using namespace std;



void No()
{
    cout<<"NO"<<endl;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,d; cin>>a>>b>>c>>d;
    if(a>b+1 || d>c+1) No();
    if(a==b+1)
    {
        if(c>0 || d>0) No();
        cout<<"YES"<<endl;
        for(int i=0;i<b;i++) cout<<"0"<<" "<<"1"<<" ";
        cout<<"0";
        return 0;
    }
    if(d==c+1)
    {
        if(a>0 || b>0) No();
        cout<<"YES"<<endl;
        for(int i=0;i<c;i++) cout<<"3"<<" "<<"2"<<" ";
        cout<<"3";
        return 0;
    }
    string s1;
    for(int i=1;i<=a;i++) s1+="0 1 ";
    string s2;
    for(int i=1;i<=d;i++) s2+="2 3 ";
    c-=d;
    b-=a;
    if(abs(b-c)>=2) No();
    cout<<"YES"<<endl;
    if(b==c)
    {
        cout<<s1;
        for(int i=0;i<b;i++) cout<<"2 1 ";
        cout<<s2;
        return 0;
    }
    if(b>c)
    {
        cout<<"1 ";
        b--;
        cout<<s1;
        for(int i=0;i<b;i++) cout<<"2 1 ";
        cout<<s2;
        return 0;
    }
    else
    {
        c--;
        cout<<s1;
        for(int i=0;i<b;i++) cout<<"2 1 ";
        cout<<s2;
        cout<<"2";
        return 0;
    }
    return 0;
}