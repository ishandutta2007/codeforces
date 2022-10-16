#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string s,t;

int znajdz(string a,int x,char z)
{
    for(int i=x;i<a.length();i++)
    {
        if(a[i]==z) return (i);
    }
    return -1;
}

void zamien()
{

}


int main()
{
    int n;
    cin>>n;
    vector<int> odp;
    cin>>s>>t;
    int w=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i]) continue;
        else
        {
            if(znajdz(s,i+1,t[i])==-1) {cout<<"-1"; return 0;}
            else
            {
                int k=znajdz(s,i+1,t[i]);
                w+=k; w-=i;
                for(int j=k;j>i;j--) {swap(s[j],s[j-1]); odp.push_back(j);}
            }
        }
    }
    cout<<w<<endl;
    for(int i=0;i<odp.size();i++) cout<<odp[i]<<" ";
    return 0;
}