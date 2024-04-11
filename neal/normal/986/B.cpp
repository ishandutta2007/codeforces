#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;
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
}


int main() {
    int N;
    IO::read_int(N);
    vector<int> numbers(N + 1);

    for (int i = 1; i <= N; i++)
        IO::read_int(numbers[i]);

    vector<bool> visited(N + 1, false);
    int cycles = 0;

    for (int i = 1; i <= N; i++)
        if (!visited[i]) {
            cycles++;

            for (int j = i; !visited[j]; j = numbers[j])
                visited[j] = true;
        }

    puts(cycles % 2 == 0 ? "Petr" : "Um_nik");
}