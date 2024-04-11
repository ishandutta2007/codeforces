// Credit to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <iomanip>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
/***********MACROS***************/
//#define int long long 
#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
#define mod 1000000007
#define inf 100000000
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
char path[10100],co[4],ch[210],s[210];

/*********FUNCTIONS**************/
void Delete()
{
    int n=strlen(path);
    if(n!=0)
    {
        int i=n-1;
        while(i>=0&&path[i]!='/')path[i--]='\0';
        if(i>=0)path[i]='\0';
    }
}
/***********MAIN**************/

signed main(){ 
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",co);
        if(strcmp(co,"cd")==0)
        {
            scanf("%s",ch);
            if(ch[0]=='/')
            {
                memset(path,0,sizeof(path));
                memset(s,0,sizeof(s));
            }
           
                for(int j=0;j<strlen(ch);j++)
                {
                int k=0;//printf("123");
                while(ch[j]!='/'&&j<strlen(ch)) s[k++]=ch[j++];
                if(strlen(s)!=0){
                    if(strcmp(s,"..")==0)Delete();
                    else {
                           strcat(path,"/");
                            strcat(path,s);
                    }
                }
                memset(s,0,sizeof(s));
            
            }
 
        }
        else
        {
            printf("%s/\n",path);
        }
        memset(co,0,sizeof(co));
    }
}