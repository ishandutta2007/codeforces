#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int d[]={31,28,31,30,31,30,31,31,30,31,30,31};

int a[3],b[3];

bool isVal(){
	if(b[1]>12) return 0;
	int add = 0;
	if(b[2]%4==0 && b[1]==2) add=1;
	if(b[0] > d[b[1]-1] + add) return 0;
	return 1;
}

bool isOk(){
	int num = a[2]-b[2];
	if(a[1] < b[1]) num --;

	if(b[1]==a[1] && a[0]<b[0]) num--;
	return num >= 18;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	scanf("%d.%d.%d",a+0,a+1,a+2);
	scanf("%d.%d.%d",b+0,b+1,b+2);
	sort(b,b+3);
	do{
		if(isVal() && isOk()){
			puts("YES");
			return 0;
		}
	}while(next_permutation(b,b+3));
    puts("NO");
    return 0;
}