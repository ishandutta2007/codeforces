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

int ans(long long int n,long long int m){
	long long int count=0;
	//cout<<n<<m<<endl;
	if (n == m){
		return 0;
	}
	if (n > m){
		return n-m;
	}
	if (n < m){
		if (m%2==1) return ans(n,m/2+1)+2;
		else return ans(n,m/2)+1;
	}
} 
const int N=1e6;
int a[N];


int main(){
	long long int m,n,count=0;
	cin>>n>>m;
	cout << ans(n,m);
	return 0;
	if (n == m){
		cout<<0;
		return 0;
	}
	if (n > m){
		cout<<n-m;
		return 0;
	}
	while (n!=m){
		if (n>m){
			n--;
			count++;
		}
		else{
			//if (n-m%2<=m/2){
				n*=2;
				count++;
			//}
			//else{
				n--;
				count ++ ;
	//		}
			//if (count<3)cout<<n-1<<endl<<m/2<<endl;
		}
		//cout << n <<endl;
	}
	
	//cout<<count;
}