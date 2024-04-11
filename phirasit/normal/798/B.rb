n = gets.strip.to_i
data = Array.new(n) { gets.strip }

inf = 10 ** 9
ans = data.map { |s|
    data.map do |ss|
        for i in (0..ss.length)
            break i if ss == s 
            ss = ss[1..-1] + ss[0]
            break inf if i+1 == ss.length
        end
    end.reduce(:+)
}.min

puts (ans >= inf ? -1 : ans)