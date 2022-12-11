n, k = gets.split.map(&:to_i)

data = []
for i in (2..n)
    while n % i == 0
        data.push(i)
        n /= i
    end
end

if data.length < k
    puts -1
else
    data[(k-1..-1)] = data[(k-1..-1)].reduce(:*)
    puts data.map(&:to_s).join(' ')
end