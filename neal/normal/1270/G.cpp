#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }

        if (number != 0 || length == 0)
            write_char(number + '0');

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}

auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

// Uniformly distributed real number in [a, b).
double real_rng(double a = 0, double b = 1) {
    assert(a <= b);
    return uniform_real_distribution<double>(a, b)(rng);
}


int N;
vector<int> A;
vector<pair<long long, int>> sorted;
vector<pair<long long, int>> negatives, positives;

bool compare_first(const pair<long long, int> &x, const pair<long long, int> &y) {
    return x.first < y.first;
}

void output_solution(const vector<int> &solution) {
    IO::write_int(solution.size(), '\n');

    for (int i = 0; i < (int) solution.size(); i++)
        IO::write_int(solution[i] + 1, i < (int) solution.size() - 1 ? ' ' : '\n');
}

const int MAX_BITSET = 125;

bool attempt_bitset() {
    shuffle(sorted.begin(), sorted.end(), rng);
    int S = sorted.size();
    vector<bitset<2 * MAX_BITSET + 1>> possible(S + 1);
    possible[0].reset();

    for (int i = 0; i < S; i++) {
        possible[i + 1] = possible[i] | possible[i] << sorted[i].first;

        if (abs(sorted[i].first) <= MAX_BITSET)
            possible[i + 1][MAX_BITSET + sorted[i].first] = true;
    }

    if (!possible[S][MAX_BITSET])
        return false;

    int target = MAX_BITSET;
    vector<int> solution;

    for (int s = S - 1; s >= 0; s--) {
        assert(possible[s + 1][target]);

        if (target == MAX_BITSET + sorted[s].first) {
            solution.push_back(sorted[s].second);
            break;
        }

        if (!possible[s][target]) {
            assert(possible[s][target - sorted[s].first]);
            solution.push_back(sorted[s].second);
            target -= sorted[s].first;
        }
    }

    output_solution(solution);
    return true;
}

void output_negative_positive_solution(int neg_count, int pos_count) {
    vector<int> solution;

    if (neg_count > 0) {
        for (int i = 0; i < neg_count; i++)
            solution.push_back(negatives[i].second);
    } else {
        for (int i = (int) negatives.size() + neg_count; i < (int) negatives.size(); i++)
            solution.push_back(negatives[i].second);
    }

    if (pos_count > 0) {
        for (int i = 0; i < pos_count; i++)
            solution.push_back(positives[i].second);
    } else {
        for (int i = (int) positives.size() + pos_count; i < (int) positives.size(); i++)
            solution.push_back(positives[i].second);
    }

    output_solution(solution);
}

void build_prefixes_and_suffixes() {
    sort(sorted.begin(), sorted.end(), compare_first);
    negatives = positives = {};

    for (auto &item : sorted)
        if (item.first < 0)
            negatives.push_back(item);
        else
            positives.push_back(item);

#ifdef NEAL
    cerr << negatives.size() << " negative and " << positives.size() << " positive" << '\n';
#endif
}

bool attempt_prefixes_and_suffixes() {
    int neg = negatives.size(), pos = positives.size();
    vector<pair<long long, int>> negative_prefixes, negative_suffixes;
    long long sum = 0;

    for (int i = 0; i < neg; i++) {
        sum += negatives[i].first;
        negative_prefixes.emplace_back(sum, i + 1);
    }

    sum = 0;

    for (int i = neg - 1; i >= 0; i--) {
        sum += negatives[i].first;
        negative_suffixes.emplace_back(sum, -(neg - i));
    }

    reverse(negative_prefixes.begin(), negative_prefixes.end());
    reverse(negative_suffixes.begin(), negative_suffixes.end());
    assert(is_sorted(negative_prefixes.begin(), negative_prefixes.end(), compare_first));
    assert(is_sorted(negative_suffixes.begin(), negative_suffixes.end(), compare_first));

    vector<pair<long long, int>> positive_prefixes, positive_suffixes;
    sum = 0;

    for (int i = 0; i < pos; i++) {
        sum += positives[i].first;
        positive_prefixes.emplace_back(sum, i + 1);
    }

    sum = 0;

    for (int i = pos - 1; i >= 0; i--) {
        sum += positives[i].first;
        positive_suffixes.emplace_back(sum, -(pos - i));
    }

    assert(is_sorted(positive_prefixes.begin(), positive_prefixes.end(), compare_first));
    assert(is_sorted(positive_suffixes.begin(), positive_suffixes.end(), compare_first));

    vector<pair<long long, int>> negative_options(2 * neg), positive_options(2 * pos);
    merge(negative_prefixes.begin(), negative_prefixes.end(), negative_suffixes.begin(), negative_suffixes.end(), negative_options.begin(), compare_first);
    merge(positive_prefixes.begin(), positive_prefixes.end(), positive_suffixes.begin(), positive_suffixes.end(), positive_options.begin(), compare_first);
    assert(is_sorted(negative_options.begin(), negative_options.end(), compare_first));
    assert(is_sorted(positive_options.begin(), positive_options.end(), compare_first));
    int no = negative_options.size(), po = positive_options.size();

    for (int i = 0, j = po - 1; i < no; i++) {
        while (j >= 0 && negative_options[i].first + positive_options[j].first > 0)
            j--;

        if (j >= 0 && negative_options[i].first + positive_options[j].first == 0) {
            output_negative_positive_solution(negative_options[i].second, positive_options[j].second);
            return true;
        }
    }

    return false;
}

void simulated_annealing() {
    vector<int> indices;

    for (auto &item : sorted)
        indices.push_back(item.second);

    vector<bool> included(N, false);
    int current_count = 0;
    long long current_sum = 0;

    const int ITERATIONS = 20 * N;
    const double INIT_TEMPERATURE = 100;
    const double FINAL_TEMPERATURE = 1;
    const int ITERATIONS_PER_TEMP = 20;

    int current_iterations = 0;
    bool print_stuck = true;

    while (true) {
        double fraction = min((double) current_iterations / ITERATIONS, 1.0);
        double temperature = INIT_TEMPERATURE * pow(FINAL_TEMPERATURE / INIT_TEMPERATURE, fraction);

        for (int iter = 0; iter < ITERATIONS_PER_TEMP; iter++) {
            current_iterations++;
            int index = indices[rng() % indices.size()];
            int new_count = current_count + (included[index] ? -1 : 1);
            long long new_sum = current_sum + (included[index] ? -A[index] : A[index]);
            long long change = abs(new_sum) - abs(current_sum);

            if (new_count == 0)
                continue;

            if (change <= 0 || real_rng() < exp(-change / temperature)) {
                included[index] = !included[index];
                current_count = new_count;
                current_sum = new_sum;

                if (current_sum == 0) {
                    vector<int> solution;

                    for (int i = 0; i < N; i++)
                        if (included[i])
                            solution.push_back(i);

                    assert((int) solution.size() == current_count);
                    output_solution(solution);

#ifdef NEAL
                    cerr << current_iterations << " iterations" << '\n';
#endif
                    return;
                }
            }
        }

#ifdef NEAL
        if (print_stuck && current_iterations >= 2 * ITERATIONS) {
            cerr << "Stuck at " << current_iterations << " iterations" << '\n';
            cerr << current_count << '\n';
            int counter = current_count;

            for (int i = 0; i < N; i++)
                if (included[i])
                    cerr << i + 1 << ' ' << (--counter > 0 ? ' ' : '\n');

            print_stuck = false;
        }
#endif
    }
}

void run_case() {
    IO::read_int(N);
    A.resize(N);

    for (int i = 0; i < N; i++)
        IO::read_int(A[i]);

    for (int i = 0; i < N; i++)
        if (A[i] == 0) {
            output_solution({i});
            return;
        }

    vector<int> location(N + 1, -1);

    for (int i = 0; i < N; i++)
        if (A[i] > 0)
            location[A[i]] = i;

    for (int i = 0; i < N; i++)
        if (A[i] < 0 && location[-A[i]] >= 0) {
            output_solution({i, location[-A[i]]});
            return;
        }

    long long negative_sum = 0, positive_sum = 0;

    for (int i = 0; i < N; i++)
        if (A[i] < 0)
            negative_sum += abs(A[i]);
        else
            positive_sum += abs(A[i]);

    sorted = {};

    for (int i = 0; i < N; i++)
        if (A[i] < 0) {
            if (abs(A[i]) <= positive_sum)
                sorted.emplace_back(A[i], i);
        } else {
            if (abs(A[i]) <= negative_sum)
                sorted.emplace_back(A[i], i);
        }

    if (attempt_bitset())
        return;

    build_prefixes_and_suffixes();

    if (attempt_prefixes_and_suffixes())
        return;

    simulated_annealing();
}

int main() {
    IO::init();

    int T;
    IO::read_int(T);

    while (T-- > 0)
        run_case();
}