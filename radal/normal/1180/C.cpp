#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
void msort(int l,int r,long long int* a){
	long long int b[100000];
	if (r-l==1){
		return;
	}
	int mid = (l+r)/2;
	msort(l, mid, a);
	msort(mid, r, a);
	int p1,p2;
	p1 = l;
	p2 = mid;
	for (int i=l; i<r; i++){
		if (p2>=r || (a[p1]<a[p2] and p1<mid)){
			b[i] = a[p1];
			p1++;
		}
		else{
			b[i] = a[p2];
			p2++;
		}
	}
	for (int i=l; i<r; i++){
		a[i]=b[i];
	}
} 
 
void merge(long long int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
 
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;  
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(long long int arr[], int l, int r) 
{ 
    if (l < r) 
    {  
        int m = l+(r-l)/2; 
   
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
int main(){
	deque <long long int> de;
	long long int n,q,b=0,j=0;
	cin >> n >>q;
	pair<long long int , long long int> a[n];
	for (int i=0; i<n; i++){
		long long int x;
		cin >> x;
		if (b < x){
			b=x;
			j=i;
		}
		de.push_front(x);
	}
	for (int i=0; i<n; i++){
		a[i].first = de.back();
		de.pop_back();
		a[i].second = de.back();
		de.pop_back();
		de.push_back(max(a[i].first,a[i].second));
		de.push_front(min(a[i].first,a[i].second));		
	}
	for (int i=0; i<q; i++){
		long long int x,y,z;
		cin >> z;
		if (z<n){
			cout<<a[z-1].first<<' '<<a[z-1].second<<endl;
		}
		else{
			z-=n;
			z%=(n-1);
			cout<<b<<' '<<min(a[z].second,a[z].first)<<endl;
		}
	}
}