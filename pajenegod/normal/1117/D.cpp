// Implementation by pajenegod and algmyr
 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma,mmx")
#pragma GCC optimize("unroll-loops")
 
// A very quick matrix multiplier mod 10^9+7
#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
 
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <random>
#include <type_traits>
#include <utility>
#include <vector>
 
using namespace std;
 
#define ull unsigned long long
#define ll long long
 
const ull MOD = 1000000007;
const int MAX_MATRIX_SIZE = 100;
 
void mult(unsigned int * __restrict__ A, unsigned int * __restrict__ B, unsigned int * __restrict__ C, int Cn, int Am, int Cm)
{
    static ull buf[MAX_MATRIX_SIZE];
 
    for (int j=0; j<Cm; ++j)
    {
        std::fill(buf,buf+Cn,0);
        int k = 0;
        for (; k+18<=Am; k+=18)
        {
            for (int _k=k; _k<k+18; ++_k)
                for (int i=0; i<Cn; ++i)
                    buf[i] += (ull)A[_k*Cn + i]*B[j*Am +_k];
            for (int i=0; i<Cn; ++i)
                buf[i] -= (-(buf[i] >> 63)) & (MOD * MOD * 9ULL);
        }
        for (; k<Am; ++k)
            for (int i=0; i<Cn; ++i)
                buf[i] += (ull)A[k*Cn + i]*B[j*Am + k];
        for (int i=0; i<Cn; ++i)
            C[j*Cn + i] = buf[i]%MOD;
    }
}
 
 
template<typename T>
struct Matrix {
    std::vector<T> data;
    int n;
    int m;
    Matrix(int n, int m) : n(n), m(m), data(n*m) {
    }
    T* operator [](int j) {
        return data.data() + j*n;
    }
    void fill(T val)
    {
        std::fill(data.begin(), data.end(), val);
    }
    Matrix operator* (Matrix& B)
    {
        assert(this->m==B.n);
        Matrix<T> C(this->n,B.m);
        mult((*this)[0],B[0],C[0],C.n,this->m,C.m);
        return C;
    }
    
    void operator<< (Matrix& B)
    {
        assert(this->m==B.n);
        int Cn = this->n;
        int Cm = B.m;
        assert(this->n==Cn);
        assert(this->m==Cm);
        auto C = new T[Cn*Cm];
        mult((*this)[0],B[0],C,Cn,this->m,Cm);
        std::copy(C,C+Cn*Cm,(*this)[0]);
        delete[] C;
    }
    
    void operator>> (Matrix& B)
    {
        assert(this->m==B.n);
        int Cn = this->n;
        int Cm = B.m;
        assert(B.n==Cn);
        assert(B.m==Cm);
        auto C = new T[Cn*Cm];
        mult((*this)[0],B[0],C,Cn,this->m,Cm);
        std::copy(C,C+Cn*Cm,B[0]);
        delete[] C;
    }
};
 
 
using Mat = Matrix<unsigned int>;
 
template<typename T>
T power(T &A, T &B, ull n)
{
    if (n==0)
        return B;
    while (n>1)    {
        if (n&1)
        {
            A>>B;
        }
        A>>A;
        n/=2;
    }
    A>>B;
    return B;
}
 
 
 
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
 
    Mat A(m,m);
    A.fill(0);
    A[0][0] += 1;
    A[m - 1][0] += 1;
    for (int i = 0; i < m - 1; ++i)
        A[i][i + 1] += 1;
 
    Mat ans(m,1);
    ans.fill(1);
    
    ans = power(A, ans, n);
    
    cout << ans[0][m - 1];
}