// C++ program to distinct permutations of the string 
#include <bits/stdc++.h>
#define ll long long int 
using namespace std; 
int N=0;
// Returns true if str[curr] does not matches with any of the 
// characters after str[start] 
bool shouldSwap(char str[], int start, int curr) 
{ 
	for (int i = start; i < curr; i++) 
		if (str[i] == str[curr]) 
			return 0; 
	return 1; 
} 

// Prints all distinct permutations in str[0..n-1] 
void findPermutations(char str[], int index, int n) 
{ 
	if (N>100) return;
	if (index >= n) { 
		for (int i=0; i<4; i++){
			for (int j=0; j<3; j++) cout << str[i*3+j]; 
			cout<<endl;
		}
		cout<<endl;
		N++;
		return; 
	} 

	for (int i = index; i < n; i++) { 

		// Proceed further for str[i] only if it 
		// doesn't match with any of the characters 
		// after str[index] 
		bool check = shouldSwap(str, index, i); 
		if (check) { 
			swap(str[index], str[i]); 
			findPermutations(str, index + 1, n); 
			swap(str[index], str[i]); 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	ll n,ou=0,od=0,t=0;
	cin >> n;
	for (ll i=0; i<n; i++){
		ll a,b;
		cin>> a >> b;
		if (a%2) ou++;
		if (b%2) od++;
		if (a%2!=b%2) t++;
	}
	if ((ou+od)%2 || (ou%2+od%2 && !t)){
		cout<<-1;
		return 0;
	}
	if (ou%2 == 0 && od%2==0){
		cout<<0<<endl;
		return 0;
	}
	cout<<1;
}