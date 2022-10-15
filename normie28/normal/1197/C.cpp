#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <bits/stdc++.h>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
int compare (const void * a, const void * b)
{
  return (*(int*)b - *(int*)a);
}
int main(){
    long a[1000000], b[1000000];
    long n, k, c;
    long long int s;
    c = 0;
    scanf("%d %d", &n, &k);
    scanf("%d", &a[0]);
if (n==k) cout << 0; else {    for (int i = 1; i<n; i++){
    	scanf("%d", &a[i]);
    	b[i-1] = a[i] - a[i-1];
	}
	qsort(b, n-1, sizeof(long), compare);
	for (int i = 0; i<k-1; i++){
		c = c + b[i];
	}
	cout << a[n-1]-a[0]-c;}
}