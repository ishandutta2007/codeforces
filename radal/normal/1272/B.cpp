#include <iostream>
#include <cmath>
using namespace std;

void merge(long long int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
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
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(long long int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
const int N=2*1e5;
long long int a[N],l[N],r[N]; 
int main(){
	int t;
	cin >>t;
	for (int i=0; i<t; i++){
		string s;
		int x=0,y=0,tr=0,tl=0,tu=0,td=0;
		cin >> s;
		for (int j=0; j<s.size(); j++){
			if (s[j] == 'L'){
				x--;
				tl++;
			}
			if (s[j] == 'R'){
				x++;
				tr++;
			}
			if (s[j] == 'D'){
				y--;
				td++;
			}
			if (s[j] == 'U'){
				y++;
				tu++;
			
			}
		}
		if (tu == 0 || td == 0){
			if (tr and tl)cout<<2<<endl;
			else {
				cout<<0<<endl;
				tr=0;
				tl=0;
			}
			if (tr)
			cout<<'R';
			if (tl)
			cout<<'L';
			cout<<endl;
			continue;
		}
		if (tl == 0 || tr == 0){
			if (td and tu)cout<<2<<endl;
			else {
				cout<<0<<endl;
				tu=0;
				td=0;
			}
			if (tu)
			cout<<'U';
			if (td)
			cout<<'D';
			cout<<endl;
			continue;
		}
		cout<<s.size()-abs(x)-abs(y)<<endl;
		if (x<0){
			tl+=x;
		}
		else{
			tr-=x;
		}
		if (y<0){
			td+=y;
		}
		else{
			tu-=y;
		}
		while (tr!=0){
			cout<<'R';
			tr--;
		}
		while (tu!=0){
			cout<<'U';
			tu--;
		}
		while (tl!=0){
			cout<<'L';
			tl--;
		}
		while (td!=0){
			cout<<'D';
			td--;
		}
		cout<<endl;
	}
	
}