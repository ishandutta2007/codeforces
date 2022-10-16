#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=505;

int A[N][N];
int B[N][N];

vector<int> wynikia[2*N];
vector<int> wynikib[2*N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>B[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            wynikia[i+j].push_back(A[i][j]);
            wynikib[i+j].push_back(B[i][j]);
        }
    }
    for(int i=0;i<=m+n-2;i++)
    {
        sort(wynikia[i].begin(),wynikia[i].end());
        sort(wynikib[i].begin(),wynikib[i].end());
        for(int j=0;j<wynikia[i].size();j++)
        {
            if(wynikia[i][j]!=wynikib[i][j]) {cout<<"NO"; return 0;}
        }
    }
    cout<<"YES";
    return 0;
}