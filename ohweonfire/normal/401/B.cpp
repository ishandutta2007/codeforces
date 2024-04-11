#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <utility>
#include <bitset>
#include <limits>
#include <stack>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#define ff first
#define ss second
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define forn(i,m,n) for(int i=m;i<=n;i++)
#define all(i,j) for(i::iterator it=j.begin;it!=j.end;it++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef set<int> si;
typedef set<ll> sll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef vector<int> vi;
typedef vector<ll> vll;
si s;
int main()
{
    int x,k;
    scanf("%d%d",&x,&k);
    s.insert(x);
    rep(i,k)
    {
              int m;
              scanf("%d",&m);
              if(m==2){int num1;scanf("%d",&num1);s.insert(num1);}
              else{int num1,num2;scanf("%d%d",&num1,&num2);s.insert(num1);s.insert(num2);}
    }
    int maxn=x-s.size();
    int minn=maxn;
    forn(i,1,x)if((!s.count(i))&&(!s.count(i+1))){minn--;s.insert(i);s.insert(i+1);}
    printf("%d %d\n",minn,maxn);
    return 0;
}