/*
    2 x 2 -> 6 solutions
    
    Solve for 2 x M
    First two columns are fixed.
    
    If last columns is BB or WW, then there
    is only one solution.

    Assume we make current column into BW or WB.
    If next column is same orientation, then next
    three columns is free. If next column is different,
    next two is free.

    So if for current column n is fixed, then f(n) = 
    f(n + 1) + f(n + 2).

    Then there is a trivial + 2 for cases BB and WW starting
    column.


    Solve for N x M
    First two rows are fixed.

    If column orientation is BB or WW, then
    ways = f(n - 3)
    BW...
    BW...
->  WB...
    .....

    ways = f(n - 3)
    WB...
    WB...
->  BW...

    If 3 valid cells are already determined in 2 x 2 square, then
    the one other cell is forced.



    Then column orientation is BW or WB.
    
    ways = f(m - 3)
    BBWB...
    WWBW...
->  BBWB...
    .......

    ways = f(m - 3)
    WWBW...
    BBWB...
->  WWBW...
    .......


    ways = f(n - 2) + f(m - 2)
    BW...
    WB...
->  .....

    ways = f(n - 2) + f(m - 2)
    WB...
    BW...
->  .....



    Total = 2 * (f(m - 1) + f(n - 1)) - 2


*/

#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 1e9 + 7;

lint N, M;
lint memo[200005];

lint fib(lint n) {
    if (n <= 0) return 1;
    if (n == 0) return 0;
    if (memo[n] != -1) return memo[n];
    return memo[n] = (fib(n - 1) + fib(n - 2)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    memset(memo, -1, sizeof(memo));
    cin >> N >> M;

    
    // cout << fib(N - 3) + fib(N - 3) << "\n"; // BW
    //                                          // BW
    
    // cout << fib(M - 3) + fib(M - 3) << "\n"; // BB
    //                                          // WW
    
    // cout << 2 * (fib(N - 2) + fib(M - 2) - 1) << "\n"; // BW
    //                                                // WB
    

    lint ans = 2 * (fib(N - 1) + fib(M - 1) - 1) % MOD;
    cout << ans << "\n";

}