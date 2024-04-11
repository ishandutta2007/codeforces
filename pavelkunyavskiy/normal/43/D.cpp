#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int64;
typedef long double ld;

int n,m;
bool trans;

void print(int x,int y,char end){
    printf("%d %d%c",x*(!trans)+y*trans,x*trans+y*(!trans),end);
}


int main(){
    cin>>n>>m;
    if (n%2!=0 && m%2==0){
    swap(n,m);
    trans^=1;
    }
    if (m==1 || n==1){
    if (n==1){
        swap(n,m);
        trans^=1;
    }   
    if (n!=2){
        printf("1\n");
        print(n,1,' ');
        print(1,1,'\n');
    }
    else
        printf("0\n");
    for (int i=0;i<n;i++)
        print(i+1,1,'\n');
    print(1,1,'\n');
    return 0;      
    }
    
    if (n%2==1){
    //cerr<<n<<" "<<m<<" "<<trans<<endl;
    //cerr<<n*(trans)+m*(!trans)<<endl;
    printf("1\n");
    print(n,m,' ');
    print(1,1,'\n');    
    for (int i=0,dj=1;i<n;i++,dj*=-1)
        for (int j=((dj==-1)?(m-1):0);j<m && j>=0;j+=dj)
        print(i+1,j+1,'\n');
    print(1,1,'\n');
    return 0;
    }
    
    //cerr<<"!!!"<<n<<" "<<m<<endl;
    
    printf("0\n");
    for (int i=0;i<n;i++)
    print(i+1,1,'\n');
    for (int i=n-1,dj=1;i>=0;i--,dj*=-1)
    for (int j=((dj==-1)?(m-1):1);j<m && j>=1;j+=dj)
        print(i+1,j+1,'\n');
    print(1,1,'\n');
    return 0;  
}