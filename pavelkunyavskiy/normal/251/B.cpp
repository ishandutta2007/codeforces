#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

int q[110];
int p[110];
int s[110];
int temp[110];

int n,k;

int m1,m2;


void NO(bool q){
	if (q){
		printf("NO\n");
		exit(0);
	}
}


void YES(bool q){
	if (q){
		printf("YES\n");
		exit(0);
	}
}

bool eq(int* a,int* b){
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			return false;
	return true;
}

void mult1(int* a,int* b){
	for (int i = 0; i < n; i++)
		temp[i] = a[b[i]];
	for (int i = 0; i < n; i++)
		a[i] = temp[i];
}

void mult2(int* a,int* b){
	for (int i = 0; i < n; i++)
		temp[b[i]] = a[i];
	for (int i = 0; i < n; i++)
		a[i] = temp[i];
}



int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i++){
    	scanf("%d",&q[i]),--q[i];
    }
    for (int i = 0; i < n; i++){
    	scanf("%d",&s[i]),--s[i];
    }

    for (int i = 0; i < n; i++)
    	p[i] = i;

    m1 = -1;

    for (int i = 0; i <= k; i++){
    	if (eq(p,s)){
    		m1 = i;
    		break;
    	}
    	mult1(p,q); 
    }

    for (int i = 0; i < n; i++)
    	p[i] = i;

    m2 = -1;

    for (int i = 0; i <= k; i++){
    	if (eq(p,s)){
    		m2 = i;
    		break;
    	}
    	mult2(p,q); 
    }

 //   cerr << m1 <<" "<<m2 << endl;

    NO(m1 == 0);
	YES((m1 != 1 || m2 != 1) && (m1 % 2) == k % 2);
	YES((m1 != 1 || m2 != 1) && (m2 % 2) == k % 2);
	YES(m1 == k);
	YES(m2 == k);
	NO(true);
    return 0;
}