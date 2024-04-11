#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#define n2 50

using namespace std;

bool visited[n2];
int color[n2];
bool mat[n2][n2];
int col=1;
int n, m;
short int a[500];

void xfs(int);

int main()
{
    //ifstream fin("input.txt");
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        mat[a-1][b-1]=true;
        mat[b-1][a-1]=true;
    }
    for(int i=0; i<n; i++)
        if(!visited[i])
        {
            xfs(i);
            col++;
        }
    int max_=0;
    for(int i=0; i<n; i++)
        if(color[i]>max_)
            max_=color[i];
    a[0]=1;
    for(int i=0; i<n-max_; i++)
    {
        for(int j=0; j<500; j++)
            a[j]*=2;
        for(int j=0; j<500-1; j++)
        {
            a[j+1]+=a[j]/10;
            a[j]=a[j]%10;
        }
    }
    bool is=false;
    for(int i=499; i>=0; i--)
    {
        if(!is && a[i]!=0)
            is=true;
        if(is)
            cout<<a[i];
    }
    cout<<endl;
    return 0;
}

void xfs(int v)
{
    visited[v]=true;
    color[v]=col;
    for(int i=0; i<n; i++)
    {
        if(mat[v][i] && !visited[i])
        {
            color[i]=col;
            xfs(i);
        }
    }
}