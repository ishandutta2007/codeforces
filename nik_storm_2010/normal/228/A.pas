var
    a:array[1..4] of longint; used:array[1..4] of boolean;
      i,j:longint; answer:longint;


begin

  readln(a[1],a[2],a[3],a[4]);
  for i:=1 to 4 do
    begin
      for j:=i+1 to 4 do if a[j]=a[i] then used[j]:=true;
      if used[i]=false then inc(answer); used[i]:=true;
    end;
  writeln(4-answer);

end.