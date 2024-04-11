#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define fi first
#define se second
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int maxn=35;
const int mod=1e9+7;

int n;
int tab[]={0,1,0,18,0,1800,0,670320,0,734832000,0,890786230,0,695720788,0,150347555,0};

int main(){
	scanf("%d",&n);
	printf("%d\n",tab[n]);
	return 0;
}