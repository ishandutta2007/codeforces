#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#define N 105
using namespace std;
int main(){
	long long n,k,a[N],i,cur=0;
	vector<long long> book;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		book.push_back(i+1);
	}
	for(i=0;i<k;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<k;i++)
	{
		cur=(cur+a[i])%book.size();
		cout<<book[cur]<<" ";
		book.erase(book.begin()+cur);
	}
	return 0;
}