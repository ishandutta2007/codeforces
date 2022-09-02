#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
using namespace std;
typedef long long ll;

const int N = 5e3+3;

char s[N][N];
int c[N];
int p[N];

bool cmp(int i, int j){
    return c[i]>c[j];
}

int main(){
   // freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
    
    int n, m;
    
    scanf("%d%d",&n,&m);
    
    for(int i=0;i<n;++i) scanf("%s",&s[i]);
    
    int ans = 0;
    
    for(int i=0;i<n;++i) p[i]=i;
    for(int j=m-1;j>=0;--j){
        for(int i=0;i<n;++i) if(s[i][j]=='0') c[i]=0; else c[i]++;
        
        stable_sort(p,p+n,cmp);
        
        for(int i=0;i<n;++i) ans=max(ans, c[p[i]]*(i+1)); 
    }
    
    cout<<ans<<endl;
    
    
    return 0;
}