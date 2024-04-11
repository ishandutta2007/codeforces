#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n,res=0,max=0;
	cin>>n;
	int a[1001];
	int b[1001];
	for (int i=1;i<=n;i++)
	{cin>>a[i]>>b[i];
	 res-=a[i]; res+=b[i];
	 if (res>max) max=res;
	}
	cout<<max;
    return 0;
}