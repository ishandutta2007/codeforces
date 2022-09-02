#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <iterator>
#include <stack>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define all(a) (a.begin(),a.end())

#define taskname "C"

using namespace std;

typedef long long int64;
typedef long double ld;


map<int,vector<int> > g;
int a[110000];
int num[110000];
int t[110000][10];

pair<int,int> tmppov[1000000];

int main(){

    
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if (g.find(a[i])==g.end())
            g.insert(mp(a[i],vector<int>()));
        num[i]=g[a[i]].size();
        g[a[i]].pb(i);
        
    }
    
    for (int i=n-2;i>=0;i--)
    {
        vector<int> tmp=g[a[i]];
        int sz=tmp.size();
        for (int j=0;j<sz;j++){
            if (tmp[j]<=i){
                t[i][j]=0;
                continue;
            }
            t[i][j]=1;
            if (a[i+1]==a[tmp[j]+1])
                t[i][j]=max(t[i][j],t[i+1][num[tmp[j]+1]]+1);
            
        }
    }
    
    int ptr=0;
    
    for (int i=0;i<n;i++){
        
        vector<int> tmp=g[a[i]];
        
        for (int j=0;j<tmp.size();j++)
            if  (tmp[j]>i && t[i][j]>=tmp[j]-i){
                tmppov[ptr]=mp(tmp[j]-i,i);
                ++ptr;
            }
    }
        
    
    sort(tmppov,tmppov+ptr);
    
    int st=0;
    
    for (int i=0;i<ptr;i++)
        if (tmppov[i].second>=st)
            st=tmppov[i].second+tmppov[i].first;
    
    printf("%d\n",n-st);
    for (int i=st;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
        
    return 0;
}