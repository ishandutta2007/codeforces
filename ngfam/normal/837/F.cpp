#include <bits/stdc++.h>

using namespace std;

const int N = 200200, M = 11;

int n, m;
unsigned long long k;
unsigned long long arr[N];
unsigned long long sum[N];


unsigned long long add(unsigned long long u,unsigned long long v){
	if(u >= k - v){
		return k;
	}
	else{
		return u + v;
	}
}
unsigned long long mul(unsigned long long u,unsigned long long v){
	if(v == 0){
		return 0;
	}
	if(u >= (k + v - 1) / v){
		return k;
	}
	else{
		return u * v;
	}
}

struct Matrix{
		unsigned long long a[M][M]; 

		Matrix(){
			memset(a, 0, sizeof a);
		}
		
		Matrix operator*(const Matrix &Other)const{
			Matrix Result;
			for(int i = 1; i < M; ++i){
				for(int j = 1; j < M; ++j){
					for(int k = 1; k < M; ++k){
						Result.a[i][j] = add(Result.a[i][j], mul(a[i][k], Other.a[k][j]));
					}
				}
			}
			return Result;
		}
}Start;

void Answer(long long x){
	cout << x;
	exit(0);
}

Matrix Power(long long x){ 
	if(x == 1){
		return Start;
	}
	Matrix Curr = Power(x / 2);
	Curr = Curr * Curr;
	if(x % 2 == 1){
		Curr = Curr * Start;
	}
	return Curr;
}

void Debug(long long x){
	Matrix Curr;
	for(int i = 1; i <= m; ++i){
		Curr.a[1][i] = arr[i];
	}
	cout << x << " : " ;
	Curr = Curr * Power(x);
	for(int i = 1; i <= m; ++i){
		cout << Curr.a[1][i] << " ";
	}
	cout << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	
	bool start = true;
	
	for(int i = 1; i <= n; ++i){
		unsigned long long x;
		cin >> x;
		if(start == true && x == 0){
		  continue;
		}
		  start = false;
			arr[++m] = x;
			if(x >= k){
				Answer(0);
			}
	}
	
	
	if(m > 10){
		int ans = 0;
		while(true){
			bool ok = false;
			for(int i = 1; i <= n; ++i){
				if(arr[i] >= k){
					Answer(ans);
				}
			}
			for(int i = 1; i <= n; ++i){
				sum[i] = sum[i - 1] + arr[i];
			}
			for(int i = 1; i <= n; ++i){
				arr[i] = sum[i];
			}
			++ans;
		}
		cout << ans;
	}
	else{
		for(int i = 1; i <= m; ++i){
			for(int j = i; j <= m; ++j){
				Start.a[i][j] = 1;
			}
		}
	//	Debug(3);
/*		for(int i = 1; i < M; ++i){
			for(int j = 1; j < M; ++j){
				cout << Start.a[i][j] << " ";
			}
			cout << endl;
		}*/
		long long low = 1, high = k, ans = k;
		while(low <= high){
			long long val = (low + high) >> 1;
			Matrix Calc;
			for(int i = 1; i <= m; ++i){
				Calc.a[1][i] = arr[i];
			}
		//	break;
	//		cout << "YES?" << endl;
			Calc = Calc * Power(val);
			//cout << "done" << endl;
			for(int i = 1; i <= m; ++i){
				if(Calc.a[1][i] >= k){
					ans = val;
					high = val - 1;
					break;
				}
			}
			if(high != val - 1){
				low = val + 1;
			}
		}
		Answer(ans);
	}
	return 0;
}