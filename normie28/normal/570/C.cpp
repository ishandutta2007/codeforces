// Credit to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
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
/*********VARIABLE****************/
using namespace std;
string str;
 
/*********FUNCTIONS**************/
bool inGroup(int index){
    return index-1>=0 && str[index-1]=='.' && index+1<str.size() && str[index+1]=='.';
}
bool alone(int index){
    return (index-1>=0?str[index-1]!='.':true) && (index+1<str.size()?str[index+1]!='.':true);
}
 
/***********MAIN**************/

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    cin >> str;
    int counter=(str[0]=='.'?1:0);
    int sum=0;
    for(int i=1;i<n;i++){
        if(str[i]=='.'){
            counter++;
        }else{
            if(counter!=0)sum+=(counter-1);
            counter=0;
        }
    }
    if(counter!=0)sum+=(counter-1);
 
    for(int i=0;i<m;i++){
        int index;
        string let;
        cin >> index >> let;
        index--;
        if(let[0]=='.' && str[index]!='.'){
            if(inGroup(index)){
                sum+=2;
            }else if(!alone(index)){
                sum+=1;
            }
        }else if(let[0]!='.' && str[index]=='.'){
            if(inGroup(index)){
                sum-=2;
            }else if(!alone(index)){
                sum-=1;
            }
        }
        cout << sum << "\n";
        str[index]=let[0];
    }
    return 0;
}

//