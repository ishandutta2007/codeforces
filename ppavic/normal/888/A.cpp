#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

typedef long long int llint;
typedef pair<int, int> pii;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MDO = 1e9 + 7;

int n,a[N];

int main(){
    scanf("%d",&n);
    int sol = 0;
    for(int i = 0;i<n;i++)
        scanf("%d",a+i);
    for(int i = 1;i<n-1;i++)
        if((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) sol++;
    printf("%d\n",sol);
    return 0;
}