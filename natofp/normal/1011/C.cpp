#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool spr(vector<int> a,int n,int p)
{
    int w=0;
    for(int i=0;i<a.size();i++)
    {

        w+=a[i]/n;
    }
    if(w>=p) return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    int m; cin>>m;
    int * a;
    int * b;
    a=new int[n];
    b=new int[n];
    for(int i=0;i<n;i++) {cin>>a[i]; if(a[i]==1) {cout<<"-1"; return 0;}}
    for(int i=0;i<n;i++) {cin>>b[i]; if(b[i]==1) {cout<<"-1"; return 0;}}
    double fuel=0;
    int k=0;
    int i=0;
    bool p=false;
    while(k<2*n)
    {
        int xd=a[i]; if(p) xd=b[i];
        double px=(m+fuel)/(xd-1);
        fuel+=px;
        p=!p;
        if(p) {i+=n-1; i%=n;}
        k++;
    }
    cout<<setprecision(15)<<fuel;
    return 0;
}