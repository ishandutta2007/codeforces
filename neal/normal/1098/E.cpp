#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


template<typename T>
struct RMQ {
    int n = 0, levels = 0;
    vector<vector<T>> range_min;

    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    void build(const vector<T> &values) {
        n = values.size();
        levels = largest_bit(n) + 1;
        range_min.resize(levels);

        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_min[0][i] = values[i];

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = __gcd(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }

    T query(int a, int b) const {
        assert(a < b);
        int level = largest_bit(b - a);
        return __gcd(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};


const int A_MAX = 1e5 + 5;

vector<long long> generate(const vector<int> &numbers) {
    int n = numbers.size();
    vector<long long> freq(A_MAX, 0);
    RMQ<int> rmq(numbers);

    for (int i = 0; i < n; i++) {
        int g = numbers[i];
        int current = i;

        while (current < n) {
            int low = current, high = n;

            while (low < high) {
                int mid = (low + high + 1) / 2;

                if (rmq.query(i, mid) == g)
                    low = mid;
                else
                    high = mid - 1;
            }

            assert(low > current);
            freq[g] += low - current;
            current = low;

            if (current < n)
                g = __gcd(g, numbers[current]);
        }
    }

    return freq;
}

// Counts x, y >= 0 such that Ax + By <= C.
long long count_triangle(long long A, long long B, long long C) {
    if (C < 0) return 0;
    if (A > B) swap(A, B);
    long long p = C / B;
    long long k = B / A;
    long long d = (C - p * B) / A;
    return count_triangle(B - k * A, A, C - A * (k * p + d + 1)) + (p + 1) * (d + 1) + k * p * (p + 1) / 2;
}

// Counts 0 <= x < RA, 0 <= y < RB such that Ax + By <= C.
long long count_triangle_rectangle_intersection(long long A, long long B, long long C, long long RA, long long RB) {
    if (C < 0) return 0;
    if (C >= A * RA + B * RB) return RA * RB;
    if (RA <= 0 || RB <= 0) return 0;
    return count_triangle(A, B, C) - count_triangle(A, B, C - A * RA) - count_triangle(A, B, C - B * RB);
}

long long count_less_equal(const vector<long long> &B, long long target) {
    assert(B.size() == A_MAX);
    int n = A_MAX - 1;
    long long sum = 0, running_count = 0, answer = 0;

    for (int i = 1, j = 1; i < n; i++) {
        // Count within the subarray of i.
        long long most = min(B[i], target / i);
        long long missing = B[i] - most;
        answer += B[i] * (B[i] + 1) / 2 - missing * (missing + 1) / 2;
        sum -= i * B[i];
        running_count -= B[i];

        if (i < j)
            answer += B[i] * running_count;

        while (j < n) {
            if (i < j)
                answer += count_triangle_rectangle_intersection(i, j, target - sum - i - j, B[i], B[j]);

            if (sum + j * B[j] <= target) {
                sum += j * B[j];
                running_count += B[j];
                j++;
            } else {
                break;
            }
        }
    }

    return answer;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> A(N);

    for (int &a : A)
        scanf("%d", &a);

    vector<long long> B = generate(A);
    long long B_count = (long long) N * (N + 1) / 2;
    long long C_count = B_count * (B_count + 1) / 2;
    long long goal = (C_count - 1) / 2;
    long long full_sum = 0;

    for (int i = 0; i < (int) B.size(); i++)
        full_sum += i * B[i];

    long long low = 0, high = full_sum;

    while (low < high) {
        long long mid = (low + high) / 2;

        if (count_less_equal(B, mid) > goal)
            high = mid;
        else
            low = mid + 1;
    }

    printf("%lld\n", low);
}