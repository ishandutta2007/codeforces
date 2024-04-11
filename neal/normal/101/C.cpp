#include <iostream>
#include <cstdio>
#include <complex>
using namespace std;

inline complex <long long> rotate (complex <long long> p)
{
    return complex <long long> (p.imag (), -p.real ());
}

inline long long dot (complex <long long> a, complex <long long> b)
{
    return a.real () * b.real () + a.imag () * b.imag ();
}

bool check (complex <long long> goal, complex <long long> p)
{
    long long norm = dot (p, p);

    if (norm == 0)
        return dot (goal, goal) == 0;

    return dot (goal, p) % norm == 0 && dot (goal, rotate (p)) % norm == 0;
}

int main ()
{
    complex <long long> A, B, C;
    cin >> A.real () >> A.imag ();
    cin >> B.real () >> B.imag ();
    cin >> C.real () >> C.imag ();
    puts (check (B - A, C) || check (B + A, C) || check (B - rotate (A), C) || check (B + rotate (A), C) ? "YES" : "NO");
    return 0;
}