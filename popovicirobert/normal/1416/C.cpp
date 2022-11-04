#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;


template<class T>
class Fenwick
{

private:

    vector<T> Data;
    int size;

    T defaultValue;

    T combine(const T& a, const T& b) 
    {  
        return a + b;
    }

public:

    Fenwick() {}

    Fenwick(int _size, T _defaultValue = T()) 
            : size(_size), 
            defaultValue(_defaultValue) 
    {

        Data.resize(size + 1, defaultValue);
    }

    void init(int _size, T _defaultValue = T())
    {
        size = _size;
        defaultValue = _defaultValue;
        Data.resize(size + 1, defaultValue);
    }

    void updateSuffix(int pos, const T& value)
    {
        for(int index = pos; index <= size; index += lsb(index))
            Data[index] = combine(Data[index], value);
    }

    T queryPrefix(int pos)
    {
        T answer = defaultValue;
        for(int index = pos; index > 0; index -= lsb(index))
            answer = combine(answer, Data[index]);

        return answer;
    }

    void updatePrefix(int pos, const T& value) 
    {
        for(int index = pos; index > 0; index -= lsb(index))
            Data[index] = combine(Data[index], value);
    }

    T querySuffix(int pos)
    {
        T answer = defaultValue;
        for(int index = pos; index <= size; index += lsb(index))
            answer = combine(answer, Data[index]);

        return answer;
    }

};


 
int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> n;
   	vector<int> arr(n + 1);
   	for(i = 1; i <= n; i++) {
   		cin >> arr[i];
   	}

    ll inv = 0;
    int ans = 0;

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);

    for(int bit = 30; bit >= 0; bit--) {
    	sort(ord.begin(), ord.end(), [&](const int& a, const int& b) {
    		if((arr[a] >> (bit + 1)) == (arr[b] >> (bit + 1))) {
    			return a < b;
    		}
    		return (arr[a] >> (bit + 1)) < (arr[b] >> (bit + 1));
   		});

    	ll a = 0, b = 0;
   		i = 0;
   		while(i < n) {
   			int cnt1 = 0, cnt0 = 0;
   			int j = i;
   			while(j < n && (arr[ord[i]] >> (bit + 1)) == (arr[ord[j]] >> (bit + 1))) {
   				if((arr[ord[j]] >> bit) & 1) {
   					b += cnt0;
   					cnt1++;
   				}
   				else {
   					a += cnt1;
   					cnt0++;
   				}
   				j++;
   			}
   			i = j;
   		}

    	inv += min(a, b);
    	if(a > b) {
    		ans |= (1 << bit);
    	}
    }

    cout << inv << " " << ans;
 
    return 0;
}