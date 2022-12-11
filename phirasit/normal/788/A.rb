n = gets.strip.to_i
a = gets.split.map(&:to_i)

s = (0...n-1).map { |i| (a[i] - a[i+1]).abs }

s1 = s.map.with_index { |v, i| i % 2 == 0 ? v : -v }
s2 = s.drop(1).map.with_index { |v, i| i % 2 == 0 ? v : -v }

def solve(arr)
    arr.push(0)
    mn = 0
    (1...arr.length).each { |i| arr[i] += arr[i-1] }
    (0...arr.length).map { |i|
        mn = [mn, arr[i]].min if i % 2 == 1
        arr[i] - mn
    }.max
end

puts [solve(s1), solve(s2)].max