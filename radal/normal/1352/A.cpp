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
	long long int y=0,n,x=0;
	cin>>n;
	for (int i=0; i<n; i++){
		string s;
		int t=0;
		cin>>s;
		for (int j=0; j<s.size(); j++){
			if (s[j]!='0') t++;
		}
		cout<<t<<endl;
		for (int j=0; j<s.size(); j++){
			if (s[j]!='0'){
				cout<<s[j];
				for (int k=j+1; k<s.size(); k++){
					cout<<'0';
				}
				cout<<' ';
			}
		}
		cout<<endl;
	}
}