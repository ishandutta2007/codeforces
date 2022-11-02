Var
    n,k,tek,leng,i,koef: longint;
     s: ansistring;



Begin

  readln(n,k);
   readln(s);
  if k = 0 then begin writeln(s); halt; end;

  tek:=0;
   for i:=1 to n-1 do
    if (s[i]='4') and (s[i+1]='7')
     then
      begin

        if (i mod 2 = 0) and (i<>1) and (s[i-1]='4')
         then
          begin
           koef:=k-tek;
            if koef mod 2 = 1 then s[i]:='7';
           break;
          end;

        inc(tek);
         if i mod 2 = 0 then begin s[i]:='7'; s[i+1]:='7'; end
                         else begin s[i]:='4'; s[i+1]:='4'; end;
        if tek = k then break;

      end;
  writeln(s);

End.