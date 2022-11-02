#include <bits/stdc++.h>
#include <algorithm>
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
int LCD (int a,int b){
	if (b>a){
		swap(a,b);
	}
	if (b == 0){
		return a;
	}
	else{
		return LCD(b,a%b);
	}
}
struct node{
	char val;
	node* p;
};

const int N=1e3;
long long int m[N];
long long int a[N];
long long int ans[N];
int main(){
	long long int n,bsum=0;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> m[i];
	}
	for (int i=0; i<n; i++){
		long long int sum = 0;
		a[i] = m[i];
		for (int j = i-1; j >= 0; j--){
			a[j] = min(m[j], a[j+1]);
		}
		for (int j = i+1; j < n; j++){
			a[j] = min(m[j],a[j-1]);
		}
		for (int j =0; j<n; j++)
			sum += a[j];
		if (sum > bsum){
			bsum = sum;
			for (int j =0; j<n; j++)
				ans[j] = a[j];
		}
	}
	for (int j =0; j<n; j++)
		cout<<ans[j]<<' ';
}