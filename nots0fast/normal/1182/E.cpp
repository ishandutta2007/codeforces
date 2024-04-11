#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define MAX 2020
#define MAX2 2020
#define pb(a) push_back(a)
#define M 1010
#define N 100100
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  2*pow(10,9);
ll modulo = pow(10,9) + 6;
ll md2 = pow(10,9) + 7;

// matrix structure for classic Matrix exponentiation type of problems


struct Matrix{ // !!! everything is an integer , and we take modulo while exponentiating (is available up to 2^30) / multiplying 
			   // n should be nonzero
	vector<vector<ll> > arr;
	int n, m;
	Matrix(){}
	Matrix(int n, int m, bool id){			// if id is true (it must be a square matrix!!) identity matrix is created
		this->n = n , this->m = m;
		arr.resize(n, vector<ll> (m, 0));
		if(id)
			fori(n)
				arr[i][i] = 1;
	}
	Matrix(vector<vector<ll> > arr){
		this->arr = arr;
		n = arr.size();
		m = arr[0].size();
	}
	Matrix Multiply(Matrix& A){
		int n1 = A.n , m1 = A.m;
		assert(m==n1);
		vector<vector<ll> > lz;
		lz.resize(n); 
		fori(n){
			lz[i].resize(m1);
			forj(m1)	lz[i][j] = 0;
		}
		fori(n)
			for(int j1=0; j1<m1; j1++)
				for(int i1=0; i1 <n1; i1++)
					lz[i][j1]+=arr[i][i1]*A.arr[i1][j1], lz[i][j1]%=modulo;
		return Matrix(lz);
	}
	vector<ll>& operator[](ll i){
		return arr[i];
	}
};
void display(Matrix& A){
	cout<<"number of rows "<<A.n<<" number of columns "<<A.m<<endl;
	fori(A.n){
		forj(A.m)
			cout<<A.arr[i][j]<<' ';
		cout<<'\n';
	}
}
#define Max_pow 62
Matrix exponentiate(Matrix& B, ll pv){
	Matrix start( B.n, B.n, 1);
	for(ll i = 62; i>-1; i--){
		start = start.Multiply(start);
		if(((ll)1<<i) & pv)
			start = start.Multiply(B);
	}
	return start;
}


ll pow_mod(ll a, ll b){
	a = a%md2;
	ll val = 1;
	for(ll i = Max_pow; i>-1; i--){
		val*=val , val%=md2;
		if(((ll)1<<i) & b)
			val *= a, val%=md2;
	}
	return val; 
}


void deal(){
	Matrix arr(14,14,0);// sum of powers, 9 - 11  powersum of c of previous guys,12 - c of exactly (not real) current guy, 13 - constant 2
	ll  n;
	ll mlt[4];
	cin>>n;
	fori(4)
		cin>>mlt[i]; // mlt[3] = c, mlt[0]  = f1 .. 
	for(ll i =0;i<9; i+=3)
		arr[i][0] = 1;
	for(ll i =1;i<9; i+=3)
		arr[i][1] = 1;
	for(ll i =2;i<9; i+=3)
		arr[i][2] = 1;
	for(ll i = 3; i<9; i++)
		arr[i-3][i] = 1;
	arr[9][9] = 1;
	arr[10][9] = 1;
	arr[11][9] = 1;
	arr[12][9] = 1;
	arr[13][9] = 1;
	arr[9][10] = 1;
	arr[10][11] = 1;
	arr[12][12] = 1;
	arr[13][12] = 1;
	arr[13][13]  = 1;
	
	
	Matrix a1(vector<vector<ll> >(1, vector<ll>( {0, 0, 1, 0 , 1, 0 , 1, 0 , 0 , 0, 0, 0, 0, 2} ) ) ) ;
	
	arr = exponentiate(arr, n-3);
//	display(arr);
	Matrix ans = a1.Multiply(arr);
//	display(ans);
//	display(arr);
//	display(a1);
	ll sms[4];
	sms[0] = ans[0][0], sms[1] = ans[0][1] , sms[2] = ans[0][2], sms[3] = ans[0][9];
	ll an = 1;
/*	fori(4)
		cout<<"powers "<<sms[i]<<endl;
*/	fori(4)
		an*=pow_mod(mlt[i], sms[i]), an%=md2;
	cout<<an;
}

int main()  
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}