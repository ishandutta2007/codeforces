var
   max, min, answer, n, i, tek, c : longint;


begin

  readln(n); read(c);
   answer:=0; max:=c; min:=c;
  for i:=1 to n-1 do
   begin
    read(c); tek:=0;
     if min>c then begin min:=c; tek:=1; end;
     if max<c then begin max:=c; tek:=1; end;
    answer:=answer+tek;
   end;
  writeln(answer);

end.