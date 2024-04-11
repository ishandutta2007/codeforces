def solve(ws)
  ts = ws.map do |w|
    case
    when w.end_with?('lios') then [:adj, :mas]
    when w.end_with?('liala') then [:adj, :fem]
    when w.end_with?('etr') then [:noun, :mas]
    when w.end_with?('etra') then [:noun, :fem]
    when w.end_with?('initis') then [:verb, :mas]
    when w.end_with?('inites') then [:verb, :fem]
    when true then nil
    end
  end
  return false if ts.any?(&:nil?)
  return true if ts.size == 1
  return false unless ts.all?{|x| x[1] == ts[0][1]}
  cb = :adj
  ts.each do |t, _|
    case cb
    when :adj
      case t
      when :noun then cb=:noun
      when :verb then return false
      end
    when :noun,:verb
      case t
      when :adj, :noun then return false
      when :verb then cb=:verb
      end
    end
  end
  return cb == :noun || cb == :verb
end

words = gets.split
puts solve(words) ? 'YES' : 'NO'