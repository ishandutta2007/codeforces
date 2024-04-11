Program A99;
Var
  d,i,incr,c,code : LongInt;
  s : AnsiString;


BEGIN

  readln(s);
  i:=1; d:=length(s);

  while s[i]<>'.' do inc(i);

  val(s[i+1],c,code);
  if c>=5 then incr:=1
          else incr:=0;

  val(s[i-1],c,code);
  if c=9 then
             begin
               writeln('GOTO Vasilisa.');
               halt;
             end;

  c:=ord(s[i-1]); inc(c,incr);
  s[i-1]:=chr(c);

  i:=1;
  while s[i]<>'.' do
                    begin
                      write(s[i]);
                      inc(i);
                    end;

END.