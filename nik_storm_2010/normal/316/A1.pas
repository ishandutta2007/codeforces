var
    used:array['A'..'Z'] of boolean; s:ansistring;
    num,k,d,i:longint; ans:int64;


begin

  readln(s); d:=length(s); num:=0; ans:=1; k:=0;
  for i:=1 to d do
  begin
    if s[i] in ['0'..'9'] then continue;
    if s[i]='?' then
    begin
      if i=1 then ans:=ans*9 else inc(k)
    end
      else
    begin
      if used[s[i]] then continue;
      if i=1 then ans:=ans*9 else ans:=ans*(10-num);
      inc(num); used[s[i]]:=true;
    end;
  end;
  write(ans); for i:=1 to k do write('0');

end.