#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())

const int SIZE = 36;
int year1[] = {31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int year2[] = {31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31};
int year3[] = {31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int year4[] = {31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
	fastIO;
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	bool is1,is2,is3,is4;
	for(int i = 0;i<SIZE;i++){
		for(int x = 0;x<=SIZE-n;x++){
			is1=is2=is3=is4=true;
			for(int j = 0;j<n;j++){
				if(year4[x + j] != a[j])is4=false;
				if(year3[x + j] != a[j])is3=false;
				if(year2[x + j] != a[j])is2=false;
				if(year1[x + j] != a[j])is1=false;
			}
			if(is1 or is2 or is3 or is4){
				cout << "YES\n";
				return 0;
			}	
		}
	}
	cout << "NO\n";
	return 0;
}