#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n,a,b,s;
	cin>>n>>a>>b>>s;

	int maxsum = (s*a)/b;
	int sum = s;

	int hole[n-1];
	for(int i=0;i<n-1;i++)
	{
		cin>>hole[i];
		sum+=hole[i];
	}
	sort(hole, hole+n-1);
	int answer=0;
	int i = n-2;
	while(sum>maxsum)
	{
		sum-= hole[i];
		i--;
		answer++;
	}
	cout<<answer<<endl;
    return 0;
}