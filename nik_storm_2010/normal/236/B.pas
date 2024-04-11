const mas:array[1..25] of longint = (2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97);
var
    tek:array[1..100,1..25] of longint; sum,nom,ss,a,b,c,i,j,k,d:longint;


procedure del(c:longint);
var cc,i:longint;
begin
  i:=1; cc:=c;
  while c<>1 do
    begin
      while c mod mas[i]=0 do begin c:=c div mas[i]; inc(tek[cc,i]); end;
      inc(i);
    end;
end;


begin

  readln(a,b,c); for i:=1 to 100 do del(i);

  for i:=1 to a do
    for j:=1 to b do
      for k:=1 to c do
      begin
        for nom:=1 to 25 do
          begin
            ss:=tek[i,nom]+tek[j,nom]+tek[k,nom];
            if ss<>0 then d:=d*ss+ss+d;
          end;
        sum:=sum+d+1; d:=0;
      end;
  writeln(sum);

end.