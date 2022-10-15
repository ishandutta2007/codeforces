// CPP program to find the kth smallest element in a range 
#include <bits/stdc++.h> 
using namespace std;
#define int long long 
#define N (int)1e5 

// Declaring a global segment tree 
vector<int> seg[N]; 

// Function to build the merge sort 
// segment tree of indices 
void build(int ci, int st, int end, 
		pair<int, int>* B) 
{ 
	if (st == end) { 
		// Using second property of B 
		seg[ci].push_back(B[st].second); 
		return; 
	} 

	int mid = (st + end) / 2; 
	build(2 * ci + 1, st, mid, B); 
	build(2 * ci + 2, mid + 1, end, B); 

	// Inbuilt merge function 
	// this takes two sorted arrays and merge 
	// them into a sorted array 
	merge(seg[2 * ci + 1].begin(), seg[2 * ci + 1].end(), 
		seg[2 * ci + 2].begin(), seg[2 * ci + 2].end(), 
		back_inserter(seg[ci])); 
} 

// Function to return the index of 
// kth smallest element in range [l, r] 
int query(int ci, int st, int end, 
		int l, int r, int k) 
{ 
	// Base case 
	if (st == end) 
		return seg[ci][0]; 

	// Finding value of 'p' as described in article 
	// seg[2*ci+1] is left node of seg[ci] 
	int p = upper_bound(seg[2 * ci + 1].begin(), 
						seg[2 * ci + 1].end(), r) 
			- lower_bound(seg[2 * ci + 1].begin(), 
						seg[2 * ci + 1].end(), l); 

	int mid = (st + end) / 2; 
	if (p >= k) 
		return query(2 * ci + 1, st, mid, l, r, k); 
	else
		return query(2 * ci + 2, mid + 1, end, l, r, k - p); 
} 

// Driver code 
signed main() 
{ 
	int arr[100001]; 
	int n,i,m,x,y,z; 
	cin>>n>>x>>y>>z;
	if ((y-z<x)and(n>=y))
	{
	m=((n-y)/(y-z))+1;
	n-=m*(y-z);
	cout<<m+(n/x);
	}
	else cout<<n/x;
}