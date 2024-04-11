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
#define int long long 
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

/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/

/*********FUNCTIONS**************/

 
/***********MAIN**************/

signed main(){ 
    int n;
    int count=0;
    int grp1=0;
    int grp2=0;
    int grp3=0;
    int grp4=0;
    cin>>n;
 
    int x;
    for(int i=0 ;i<n; i++) //reading values, counting frequency
    {
        cin>>x;
        if(x==1)
        grp1++;
        else if(x==2)
        grp2++;
        else if (x==3)
        grp3++;
        else if (x==4)
        grp4++;
    }
    count= count+grp4;  //to form 4s team, straightforward 
    
    count= count+(grp2/2); // this line is to form group of 2+2
 
    grp2=grp2%2;
    
    if (grp3<=grp1)   //to form 3+1s team
    {
        count=count+grp3;
        grp1= grp1-grp3;
        grp3=0;
        count= count+ grp1/4;
        grp1=grp1%4;
    }
 
    if (grp3>grp1)      //to form 3+1s team
    {
        count= count+grp1;
        grp3= grp3-grp1;
        grp1=0;    
    }
    count= count+grp3; // for the remaining 3s 
 
    if( (grp1+ grp2*2<=4) && grp1+ grp2*2>0 )
    {
        count++;
        grp1=0;
        grp2=0;
    }
    else if(grp1==3 && grp2==1)
    {
        count +=2;
        grp1=0;
        grp2=0;
    }
   
    count= count+grp1;      // to form 1+1+1+1 like types
    cout<<count<<endl;
    
}

//