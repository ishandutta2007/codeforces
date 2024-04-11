#include <bits/stdc++.h>
using namespace std;

typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define F first
#define S second
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

typedef double Num;
const Num PI = 3.141592653589793238462643383279L;
typedef complex<Num> Complex;

void fft_main(int n, Num theta, Complex a[]) {
	for(int m = n; m >= 2; m >>= 1) {
		int mh = m >> 1;
		Complex thetaI = Complex(0, theta);
		for (int i = 0; i < mh; ++i) {
			Complex w = exp((Num)i*thetaI);
			for(int j = i; j < n; j += m) {
				int k = j + mh;
				Complex x = a[j] - a[k];
				a[j] += a[k];
				a[k] = w * x;
			}
		}
		theta *= 2;
	}
	int i = 0;
	for (int j = 1; j < n - 1; ++j) {
		for(int k = n >> 1; k > (i ^= k); k >>= 1) ;
		if(j < i) swap(a[i], a[j]);
	}
}
void fft(int n, Complex a[], bool rev) {
	if (rev){
		fft_main(n, -2 * PI / n, a);
		for (int i = 0; i < n; ++i) a[i] /= n;
	}
	else
		fft_main(n, 2 * PI / n, a); 	
}
void fft2(vector<vector<Complex>> & a, bool rev) {
	int n = a.size();
	int m = a[0].size();
	for (int i = 0; i < n; ++i) {
		fft(m, &a[i][0], rev);
	}
	for (int i = 0; i < m; ++i) {
		vector<Complex> t;
		for (int j = 0; j < n; ++j) t.push_back(a[j][i]);
		fft(n, &t[0], rev);
		for (int j = 0; j < n; ++j) a[j][i] = t[j];
	}
}
void convolution(vector<vector<Complex>> &v, vector<vector<Complex>> &w) {
	int n = 1, vwn = max(v.size(), w.size());
	while(n < vwn) n <<= 1;
	v.resize(n), w.resize(n);
	int m = 1, vwm = max(v[0].size(), w[0].size());
	while(m < vwm) m <<= 1;
	for (auto& it : v) it.resize(m);
	for (auto& it : w) it.resize(m);
	fft2(v, 0);
	fft2(w, 0);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) v[i][j] *= w[i][j];
	fft2(v, 1);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector<string> a(n);
	for (auto& it : a) cin >> it;

	int r, c; cin >> r >> c;
	int no = r*c;
	vector<string> b(r);
	for (auto& it : b) cin >> it, no -= count(it.begin(), it.end(), '?');

	a.resize(n + r);
	for(auto& it : a) it.resize(m + c);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int I = i; I < n + r; I += n) {
				for (int J = j; J < m + c; J += m) {
					a[I][J] = a[i][j];
				}
			}
		}
	}
	vector<vector<Complex>> A(n+r, vector<Complex>(m+c));
	for (int i = 0; i < n + r; ++i) {
		for (int j = 0; j < m + c; ++j) {
			Num angle = 2*PI*(a[i][j]-'a')/26;
			A[i][j] = Complex(cos(angle), sin(angle));
		}
	}
	vector<vector<Complex>> B(r, vector<Complex>(c));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (b[i][j] == '?') continue;
			Num angle = -2*PI*(b[i][j]-'a')/26;
			B[r-i-1][c-j-1] = Complex(cos(angle), sin(angle));
		}
	}

	convolution(A, B);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int h = A[i + r - 1][j + c - 1].real()+1e-5;
			cout << (h == no);
		}
		cout << "\n";
	}


	return 0;
}