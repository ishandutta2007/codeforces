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
long long int a[N];

int main(){
	long long int t;
	cin >> t;
	for (int i=0; i<t; i++){
		int n;
		cin >> n;
		if (n%2 == 0){
			for (int j=0; j<n/2; j++){
				cout << 1;
			}
		}
		else{
			cout<<7;
			n-=3;
			for (int j=0; j<n/2; j++){
				cout << 1;
			}
		}
		cout<<endl;
	}
}