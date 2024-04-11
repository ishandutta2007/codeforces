#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
void merge(int arr[], int l, int m, int r) 
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
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
}

const int N=1e6;
int a[N];


int main(){
	long long int t;
	cin>>t;
	for (int i=0; i<t; i++){
		long long int n,k;
		cin>>n>>k;
		if (k<n){
			cout<<k<<endl;
			continue;
		}
		if (k==n){
			cout<<k+1;
		}
		if (k>n and k%(n-1)==0){
			cout<<k/(n-1)*n-1;
		}
		if (k>n and k%(n-1)!=0){
			cout<<k/(n-1)*n+k%(n-1);
		}
		cout<<endl;
	}
}