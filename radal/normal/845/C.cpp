#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N=2*1e5;
pair<long long int , long long int> a[N];
/*void msort(int l,int r,long long int* a){
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
} */
 
void merge(int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
 
    int L[n1], R[n2],w[n1],v[n2]; 
  
    for (i = 0; i < n1; i++) {
        L[i] = a[l + i].first;
		w[i] = a[l + i].second;
	//	cout<<w[i]<<"kkk"<<endl;
	}
    for (j = 0; j < n2; j++) {
        R[j] = a[m + 1+ j].first; 
		v[j] = a[m+ 1 + j].second;
	//	cout<<v[j]<<"jgri"<<endl;
  	}
    i = 0;  
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k].first = L[i];
			a[k].second = w[i];
	//		cout<<w[i]<<"00111111000"<<endl;
            i++;
        } 
        else
        { 
            a[k].first = R[j];
			a[k].second = v[j];
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        a[k].first = L[i]; 
        a[k].second = w[i];
        i++;  
        k++;
    } 
  
    while (j < n2) 
    { 
        a[k].first = R[j];
		a[k].second = v[j]; 
        j++;
        k++;
    } 
} 
  
void mergeSort(int l, int r) 
{ 

    if (l < r) 
    {  
        int m = l+(r-l)/2; 
   
        mergeSort(l, m); 
        mergeSort(m+1, r); 
  
        merge(l, m, r); 
    } 
} 
int main(){
	long long int n;
	cin >> n;
	stack <pair<long long int,long long int> >f,s;
	for (int i=0; i<n; i++){
		cin >> a[i].first >>a[i].second;
	}
	mergeSort(0,n-1);
	for (int i=0; i<n; i++){
		if (f.empty()){
			f.push(a[i]);
			continue;
		}
		if (s.empty()){
			s.push(a[i]);
			continue;
		}
		if (a[i].first>f.top().second){
			f.push(a[i]);
			continue;
		}
		if (a[i].first > s.top().second){
			s.push(a[i]);
			continue;
		}
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES";
}