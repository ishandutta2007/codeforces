n, k = gets.split.map(&:to_i)
data = gets.split.map(&:to_i)

min = data.min
if data.all? { |i| i % k == min % k }
    puts data.map { |i| (i - min) / k }.reduce(0, :+)
else
    puts -1
end