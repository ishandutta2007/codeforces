import Control.Applicative

-- blabla
main :: IO ()
main = do
    [a,b] <- map read . words <$> getContents :: IO [Integer]
    print $ a+b